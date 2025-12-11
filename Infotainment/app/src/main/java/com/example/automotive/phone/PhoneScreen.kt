package com.example.automotive.phone

import androidx.compose.runtime.Composable
import androidx.navigation.NavHostController
import com.example.automotive.SimpleScreen

@Composable
fun PhoneScreen(navController: NavHostController) {
    SimpleScreen(
        title = "Phone",
        description = "Add list of contacts and call logs tab",
        navController = navController
    )
}