package com.example.automotive.navigation

import androidx.compose.material3.MaterialTheme
import androidx.compose.runtime.Composable
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.rememberNavController
import com.example.automotive.menu.MainMenuScreen
import com.example.automotive.media.MediaScreen
import com.example.automotive.media.PlaylistScreen
import com.example.automotive.navigationapp.NavigationScreen
import com.example.automotive.settings.SettingsScreen
import com.example.automotive.phone.PhoneScreen
import com.example.automotive.radio.RadioScreen
import com.example.automotive.climate.ClimateScreen

/**
 * --------------------------------------------------------------------
 *  Root composable that holds the NavController
 * --------------------------------------------------------------------
 */
@Composable
fun AppNavGraph() {
    MaterialTheme {
        val navController = rememberNavController()
        NavHost(
            navController = navController,
            startDestination = Screen.Menu.route
        ) {
            composable(Screen.Menu.route) { MainMenuScreen(navController) }
            composable (Screen.Playlist.route){ PlaylistScreen(navController) }
            composable(Screen.Media.route) { MediaScreen(navController) }
            composable(Screen.Navigation.route) { NavigationScreen(navController) }
            composable(Screen.Settings.route) { SettingsScreen(navController) }
            composable(Screen.Phone.route) { PhoneScreen(navController) }
            composable(Screen.Radio.route) { RadioScreen(navController) }
            composable(Screen.Climate.route) { ClimateScreen(navController) }
        }
    }
}