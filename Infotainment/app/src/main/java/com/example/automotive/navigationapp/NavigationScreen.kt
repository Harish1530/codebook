package com.example.automotive.navigationapp

import androidx.compose.runtime.Composable
import androidx.navigation.NavHostController
import com.example.automotive.SimpleScreen

@Composable
fun NavigationScreen(navController: NavHostController) {
    SimpleScreen(
        title = "Navigation",
        description = "Add map view and routing UI here",
        navController = navController
    )
}