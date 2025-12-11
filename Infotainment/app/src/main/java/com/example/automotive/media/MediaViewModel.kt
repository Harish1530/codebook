package com.example.automotive.media

import android.content.Context
import android.net.Uri
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableIntStateOf
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.setValue
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import androidx.media3.common.MediaItem
import androidx.media3.common.PlaybackException
import androidx.media3.common.Player
import com.example.automotive.R
import kotlinx.coroutines.Job
import kotlinx.coroutines.delay
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.StateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.launch
import java.util.concurrent.TimeUnit

// RawSong Definition
data class RawSong(
    val resourceId: Int,
    val title: String,
    val artist: String
)

class MediaViewModel : ViewModel() {

    // Make the property nullable to avoid lateinit issues
    private var myMediaPlayer: MyMediaPlayer? = null
    private var progressJob: Job? = null

    // UI State for the player
    private val _playerState = MutableStateFlow(PlayerState())
    val playerState: StateFlow<PlayerState> = _playerState.asStateFlow()

    // Playlist state for UI
    var mediaItems by mutableStateOf(emptyList<MediaItem>())
        private set
    var currentSongIndex by mutableIntStateOf(-1)
        private set

    private val rawMusicFiles = listOf(
        RawSong(R.raw.song1, "First Song", "Helix_1"),
        RawSong(R.raw.song2, "Troublesome Song", "Boosted"),
        RawSong(R.raw.song3, "Crushing time", "Lisa")
    )

    fun initializePlayer(context: Context) {
        if (myMediaPlayer == null) {
            myMediaPlayer = MyMediaPlayer(context).apply {
                addListener(object : Player.Listener {
                    override fun onPlaybackStateChanged(playbackState: Int) {
                        val isPlaying = mediaPlayer?.isPlaying == true
                        val state = playbackState.toPlayerState(isPlaying)
                        _playerState.value = _playerState.value.copy(current = state)
                        if (isPlaying) {
                            startProgressUpdate()
                        } else {
                            stopProgressUpdate()
                        }
                    }

                    override fun onMediaItemTransition(mediaItem: MediaItem?, reason: Int) {
                        super.onMediaItemTransition(mediaItem, reason)
                        currentSongIndex = myMediaPlayer?.mediaPlayer?.currentMediaItemIndex ?: -1
                    }

                    override fun onPlayerError(error: PlaybackException) {
                        super.onPlayerError(error)
                        _playerState.value = _playerState.value.copy(current = MediaPlayerState.ERROR)
                    }
                })
            }
        }
    }

    fun loadSongs(context: Context) {
        if (mediaItems.isEmpty()) {
            // Ensure the player is initialized before loading songs
            if (myMediaPlayer == null) {
                initializePlayer(context)
            }

            mediaItems = rawMusicFiles.map { rawSong ->
                val uri = "android.resource://${context.packageName}/${rawSong.resourceId}"
                MediaItem.Builder()
                    .setUri(Uri.parse(uri))
                    .setMediaId(rawSong.resourceId.toString())
                    .setMediaMetadata(
                        androidx.media3.common.MediaMetadata.Builder()
                            .setTitle(rawSong.title)
                            .setArtist(rawSong.artist)
                            .build()
                    )
                    .build()
            }
            myMediaPlayer?.mediaPlayer?.setMediaItems(mediaItems)
        }
    }

    fun playSong(index: Int) {
        myMediaPlayer?.let { player ->
            if (index in mediaItems.indices) {
                player.setMediaItemsAndPlay(mediaItems, index)
                currentSongIndex = index
            }
        }
    }

    fun playPause() {
        myMediaPlayer?.let { player ->
            if (player.mediaPlayer?.isPlaying == true) {
                player.pause()
            } else {
                player.play()
            }
        }
    }

    fun skipNext() {
        myMediaPlayer?.skipNext()
    }

    fun skipPrevious() {
        myMediaPlayer?.skipPrevious()
    }

    fun fastForward() {
        myMediaPlayer?.fastForward()
    }

    fun rewind() {
        myMediaPlayer?.rewind()
    }

    fun seekTo(position: Long) {
        myMediaPlayer?.seekTo(position)
    }

    private fun startProgressUpdate() {
        progressJob?.cancel()
        progressJob = viewModelScope.launch {
            while (myMediaPlayer?.mediaPlayer?.isPlaying == true) {
                val duration = myMediaPlayer?.mediaPlayer?.duration?.coerceAtLeast(0) ?: 0
                _playerState.value = _playerState.value.copy(
                    currentPosition = myMediaPlayer?.mediaPlayer?.currentPosition ?: 0,
                    totalDuration = duration
                )
                delay(TimeUnit.SECONDS.toMillis(1))
            }
        }
    }

    private fun stopProgressUpdate() {
        progressJob?.cancel()
    }

    override fun onCleared() {
        super.onCleared()
        myMediaPlayer?.release()
        stopProgressUpdate()
    }
}
