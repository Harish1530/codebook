package com.example.automotive.menu

import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.lazy.grid.GridCells
import androidx.compose.foundation.lazy.grid.LazyVerticalGrid
import androidx.compose.foundation.lazy.grid.items
import androidx.compose.material3.*
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import androidx.navigation.NavHostController
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.AcUnit
import androidx.compose.material.icons.filled.LibraryMusic
import androidx.compose.material.icons.filled.LocalPhone
import androidx.compose.material.icons.filled.Map
import androidx.compose.material.icons.filled.Radio
import androidx.compose.material.icons.filled.Settings
import androidx.compose.ui.graphics.vector.ImageVector
import androidx.compose.ui.text.style.TextAlign
import com.example.automotive.navigation.Screen

data class MainMenuItem(
    val title: String,
    val icon: ImageVector,
    val destination: Screen
)

val menuItems = listOf(
    MainMenuItem("Media", Icons.Default.LibraryMusic, Screen.Playlist),
    MainMenuItem("Navigation", Icons.Default.Map, Screen.Navigation),
    MainMenuItem("Settings", Icons.Default.Settings, Screen.Settings),
    MainMenuItem("Phone", Icons.Default.LocalPhone, Screen.Phone),
    MainMenuItem("Radio", Icons.Default.Radio, Screen.Radio),
    MainMenuItem("Climate", Icons.Default.AcUnit, Screen.Climate)
)

@Composable
fun MainMenuScreen(navController: NavHostController) {
    Scaffold { innerPadding ->
        LazyVerticalGrid(
            columns = GridCells.Fixed(3),
            modifier = Modifier
                .fillMaxSize()
                .padding(innerPadding)
                .padding(16.dp),
            verticalArrangement = Arrangement.spacedBy(25.dp),
            horizontalArrangement = Arrangement.spacedBy(25.dp)
        ) {
            items(menuItems) { item ->
                MenuGridItem(item) { navController.navigate(item.destination.route) }
            }
        }
    }
}

@Composable
private fun MenuGridItem(item: MainMenuItem, onClick: () -> Unit) {
    Card(modifier = Modifier.size(180.dp)) {
        Column(
            modifier = Modifier
                .fillMaxSize()
                .clickable(onClick = onClick)
                .padding(14.dp),
            verticalArrangement = Arrangement.Center,
            horizontalAlignment = Alignment.CenterHorizontally
        ) {
            Icon(
                imageVector = item.icon,
                contentDescription = item.title,
                modifier = Modifier.size(40.dp)
            )
            Spacer(modifier = Modifier.height(8.dp))
            Text(
                text = item.title,
                style = MaterialTheme.typography.titleMedium,
                textAlign = TextAlign.Center
            )
        }
    }
}