package com.example.automotive.media

import androidx.compose.foundation.background
import androidx.compose.foundation.layout.*
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.automirrored.filled.ArrowBack
import androidx.compose.material.icons.filled.*
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.unit.dp
import androidx.lifecycle.viewmodel.compose.viewModel
import androidx.navigation.NavHostController

@Composable
fun MediaScreen(
    navController: NavHostController,
    mediaViewModel: MediaViewModel = viewModel()
) {
    val context = LocalContext.current

    // Initialize player and load songs once when the Composable is first launched
    LaunchedEffect(Unit) {
        mediaViewModel.initializePlayer(context)
        mediaViewModel.loadSongs(context)
    }

    // Observe player state and other state variables
    val playerState by mediaViewModel.playerState.collectAsState()
    val isPlaying = playerState.current == MediaPlayerState.PLAYING
    val currentSongIndex = mediaViewModel.currentSongIndex

    val currentSongTitle = if (currentSongIndex in mediaViewModel.mediaItems.indices) {
        mediaViewModel.mediaItems[currentSongIndex].mediaMetadata.title.toString()
    } else {
        "No Song Playing"
    }

    val currentSongArtist = if (currentSongIndex in mediaViewModel.mediaItems.indices) {
        mediaViewModel.mediaItems[currentSongIndex].mediaMetadata.artist.toString()
    } else {
        "Unknown Artist"
    }

    Column {
        // Top App Bar
        Box(
            modifier = Modifier
                .fillMaxWidth()
                .height(60.dp)
                .background(MaterialTheme.colorScheme.primaryContainer)
        ) {
            Row(
                verticalAlignment = Alignment.CenterVertically,
                modifier = Modifier
                    .fillMaxSize()
                    .padding(16.dp)
            ) {
                // Add a back button for navigation
                IconButton(onClick = { navController.popBackStack() }) {
                    Icon(
                        imageVector = Icons.AutoMirrored.Filled.ArrowBack,
                        contentDescription = "Back",
                        tint = MaterialTheme.colorScheme.onPrimaryContainer
                    )
                }

                Spacer(modifier = Modifier.width(16.dp))
                Text(
                    text = "Infotainment Media Player",
                    color = MaterialTheme.colorScheme.onPrimaryContainer,
                    style = MaterialTheme.typography.titleMedium
                )
                Spacer(modifier = Modifier.weight(1f))
                Icon(
                    imageVector = Icons.Filled.Search,
                    contentDescription = "Search",
                    tint = MaterialTheme.colorScheme.onPrimaryContainer
                )
            }
        }

        Spacer(modifier = Modifier.height(32.dp))

        // Display current song title and artist
        Text(
            text = currentSongTitle,
            style = MaterialTheme.typography.headlineMedium,
            modifier = Modifier
                .fillMaxWidth()
                .padding(horizontal = 16.dp)
        )
        Text(
            text = currentSongArtist,
            style = MaterialTheme.typography.bodyMedium,
            modifier = Modifier
                .fillMaxWidth()
                .padding(horizontal = 16.dp)
        )

        Spacer(modifier = Modifier.height(16.dp))

        // Seekbar
        if (playerState.totalDuration > 0) {
            Slider(
                value = playerState.currentPosition.toFloat(),
                onValueChange = { mediaViewModel.seekTo(it.toLong()) },
                valueRange = 0f..playerState.totalDuration.toFloat(), // CORRECTED: Convert Long to Float
                modifier = Modifier
                    .fillMaxWidth()
                    .padding(horizontal = 16.dp)
            )
        } else {
            LinearProgressIndicator(
                modifier = Modifier
                    .fillMaxWidth()
                    .padding(horizontal = 16.dp)
            )
        }

        Spacer(modifier = Modifier.height(8.dp))

        // Duration text
        Row(
            modifier = Modifier
                .fillMaxWidth()
                .padding(horizontal = 16.dp),
            horizontalArrangement = Arrangement.SpaceBetween
        ) {
            Text(text = formatDuration(playerState.currentPosition))
            Text(text = formatDuration(playerState.totalDuration))
        }

        Spacer(modifier = Modifier.height(16.dp))

        // Playback controls
        Row(
            horizontalArrangement = Arrangement.SpaceAround,
            modifier = Modifier.fillMaxWidth(),
            verticalAlignment = Alignment.CenterVertically
        ) {
            IconButton(onClick = { mediaViewModel.skipPrevious() }) {
                Icon(Icons.Filled.SkipPrevious, contentDescription = "Previous")
            }
            IconButton(onClick = { mediaViewModel.rewind() }) {
                Icon(Icons.Filled.FastRewind, contentDescription = "Rewind")
            }
            IconButton(onClick = { mediaViewModel.playPause() }) {
                Icon(
                    imageVector = if (isPlaying) Icons.Filled.Pause else Icons.Filled.PlayArrow,
                    contentDescription = "Play/Pause"
                )
            }
            IconButton(onClick = { mediaViewModel.fastForward() }) {
                Icon(Icons.Filled.FastForward, contentDescription = "Fast Forward")
            }
            IconButton(onClick = { mediaViewModel.skipNext() }) {
                Icon(Icons.Filled.SkipNext, contentDescription = "Next")
            }
        }
    }
}

// Helper function for formatting duration
fun formatDuration(duration: Long): String {
    val seconds = duration / 1000
    val minutes = seconds / 60
    val remainingSeconds = seconds % 60
    return String.format("%02d:%02d", minutes, remainingSeconds)
}
