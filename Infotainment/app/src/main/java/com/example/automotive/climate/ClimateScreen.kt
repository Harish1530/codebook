package com.example.automotive.climate

import androidx.compose.runtime.Composable
import androidx.navigation.NavHostController
import com.example.automotive.SimpleScreen

@Composable
fun ClimateScreen(navController: NavHostController) {
    SimpleScreen(
        title = "Climate Screen",
        description = "Add pictures of weather and temperature",
        navController = navController
    )
}