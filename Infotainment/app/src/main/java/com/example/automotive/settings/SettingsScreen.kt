package com.example.automotive.settings

import androidx.compose.runtime.Composable
import androidx.navigation.NavHostController
import com.example.automotive.SimpleScreen

@Composable
fun SettingsScreen(navController: NavHostController) {
    SimpleScreen(
        title = "Settings",
        description = "Add volume, brightness, Bluetooth, etc.",
        navController = navController
    )
}