package com.example.automotive.media

import android.content.Context
import androidx.media3.common.MediaItem
import androidx.media3.common.PlaybackException
import androidx.media3.common.Player
import androidx.media3.exoplayer.ExoPlayer

class MyMediaPlayer(
    private val context: Context
) {
    var mediaPlayer: ExoPlayer? = null
        private set

    init {
        mediaPlayer = ExoPlayer.Builder(context).build()
    }

    // The new function that accepts a list of MediaItem objects directly.
    fun setMediaItemsAndPlay(mediaItems: List<MediaItem>, index: Int) {
        mediaPlayer?.let { player ->
            // Stop current playback before preparing a new playlist
            player.stop()
            player.clearMediaItems() // Clear the old playlist

            // Set the new list of media items
            player.setMediaItems(mediaItems)
            player.seekTo(index, 0)
            player.prepare()
            player.play()
        }
    }

    // Additional methods for controlling playback
    fun play() {
        mediaPlayer?.play()
    }

    fun pause() {
        mediaPlayer?.pause()
    }

    fun skipNext() {
        mediaPlayer?.seekToNextMediaItem()
    }

    fun skipPrevious() {
        mediaPlayer?.seekToPreviousMediaItem()
    }

    fun seekTo(position: Long) {
        mediaPlayer?.seekTo(position)
    }

    //fun setPlaybackSpeed(speed: Float) { mediaPlayer?.setPlaybackSpeed(speed) }
    fun fastForward() {
        mediaPlayer?.seekForward()
    }

    fun rewind() {
        mediaPlayer?.seekBack()
    }

    fun addListener(listener: Player.Listener) {
        mediaPlayer?.addListener(listener)
    }

    fun release() {
        mediaPlayer?.release()
        mediaPlayer = null
    }
}

