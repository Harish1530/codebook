package com.example.automotive.navigation

sealed class Screen(val route: String) {
    object Menu : Screen("menu")
    object Playlist : Screen("playlist")
    object Media : Screen("media")
    object Navigation : Screen("navigation")
    object Settings : Screen("settings")
    object Phone : Screen("Phone")
    object Radio : Screen("Radio")
    object Climate : Screen("Climate")
}