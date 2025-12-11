package com.example.automotive.media

import android.Manifest
import android.os.Build
import android.widget.Toast
import androidx.activity.compose.rememberLauncherForActivityResult
import androidx.activity.result.contract.ActivityResultContracts
import androidx.compose.foundation.background
import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.itemsIndexed
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.Search
import androidx.compose.material3.*
import androidx.compose.material3.HorizontalDivider
import androidx.compose.runtime.Composable
import androidx.compose.runtime.LaunchedEffect
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import androidx.lifecycle.viewmodel.compose.viewModel
import androidx.navigation.NavHostController

@Composable
fun PlaylistScreen(
    navController: NavHostController,
    mediaViewModel: MediaViewModel = viewModel()
) {
    val context = navController.context

    val requestPermissionLauncher = rememberLauncherForActivityResult(
        contract = ActivityResultContracts.RequestPermission()
    ) { isGranted ->
        if (isGranted) {
            mediaViewModel.loadSongs(context)
        } else {
            Toast.makeText(context, "Permission denied. Cannot load songs.", Toast.LENGTH_SHORT).show()
        }
    }


    //Load songs once when the screen is first composed
    LaunchedEffect(Unit) {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.TIRAMISU) {
            requestPermissionLauncher.launch(Manifest.permission.READ_MEDIA_AUDIO)
        } else {
            requestPermissionLauncher.launch((Manifest.permission.READ_EXTERNAL_STORAGE))
        }
    }

    val songs = mediaViewModel.mediaItems

    Column {
        // Top App Bar (Mimicking TopAppBar)
        Box(
            modifier = Modifier
                .fillMaxWidth()
                .height(60.dp) // Adjust height as needed
                .background(MaterialTheme.colorScheme.primaryContainer) // Or your desired color
        ) {
            Row(
                verticalAlignment = Alignment.CenterVertically,
                modifier = Modifier
                    .fillMaxSize()
                    .padding(16.dp)
            ) {
                Text(
                    text = "Playlist",
                    color = MaterialTheme.colorScheme.onPrimaryContainer, // Or your desired text color
                    style = MaterialTheme.typography.titleMedium
                )
                Spacer(modifier = Modifier.weight(1f))
                // Add any icons or actions here, like a search icon
                Icon(
                    imageVector = Icons.Filled.Search,
                    contentDescription = "Search",
                    tint = MaterialTheme.colorScheme.onPrimaryContainer
                )
            }
        }

        // Content (LazyColumn)
        LazyColumn(modifier = Modifier.padding(16.dp)) {
            itemsIndexed(songs) { index, mediaItem ->
                SongItem(
                    songTitle = mediaItem.mediaMetadata.title.toString(), // Use real title if available
                    onClick = {
                        mediaViewModel.playSong(index)
                        navController.navigate("media")
                    }
                )
            }
        }
    }
}

@Composable
fun SongItem(songTitle: String, onClick: () -> Unit) {
    Row(
        modifier = Modifier
            .fillMaxWidth()
            .clickable(onClick = onClick)
            .padding(16.dp)
    ) {
        Text(songTitle, style = MaterialTheme.typography.bodyLarge)
    }
    HorizontalDivider(Modifier, DividerDefaults.Thickness, DividerDefaults.color)
}