package com.example.automotive.radio

import androidx.compose.runtime.Composable
import androidx.navigation.NavHostController
import com.example.automotive.SimpleScreen

@Composable
fun RadioScreen(navController: NavHostController) {
    SimpleScreen(
        title = "Radio",
        description = "Add list for channels and tab for selection",
        navController = navController
    )
}