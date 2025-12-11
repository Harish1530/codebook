// File: MediaPlayerState.kt
package com.example.automotive.media

import androidx.media3.common.Player

enum class MediaPlayerState {
    IDLE, BUFFERING, READY, PLAYING, PAUSED, ENDED, ERROR
}

data class PlayerState(
    val current: MediaPlayerState = MediaPlayerState.IDLE,
    val totalDuration: Long = 0L,
    val currentPosition: Long = 0L
)

fun Int.toPlayerState(isPlaying: Boolean): MediaPlayerState {
    return when (this) {
        Player.STATE_IDLE -> MediaPlayerState.IDLE
        Player.STATE_BUFFERING -> MediaPlayerState.BUFFERING
        Player.STATE_READY -> if (isPlaying) MediaPlayerState.PLAYING else MediaPlayerState.PAUSED
        Player.STATE_ENDED -> MediaPlayerState.ENDED
        else -> MediaPlayerState.IDLE
    }
}

fun MediaPlayerState.copy(isPlaying: Boolean): MediaPlayerState {
    return when (this) {
        MediaPlayerState.PLAYING -> if (isPlaying) MediaPlayerState.PLAYING else MediaPlayerState.PAUSED
        MediaPlayerState.PAUSED -> if (isPlaying) MediaPlayerState.PLAYING else MediaPlayerState.PAUSED
        else -> this
    }
}
