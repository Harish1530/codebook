package com.example.automotive

import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Button
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import androidx.navigation.NavHostController


@Composable
fun SimpleScreen(
    title: String,
    description: String,
    navController: NavHostController
) {
    // Scaffold without a topBar
    Scaffold { innerPadding ->
        Column(
            modifier = Modifier
                .fillMaxSize()
                .padding(innerPadding)
                .padding(24.dp),
            verticalArrangement = Arrangement.Center,
            horizontalAlignment = Alignment.CenterHorizontally
        ) {
            Text(text = title, style = MaterialTheme.typography.headlineLarge)
            Spacer(Modifier.height(16.dp))
            Text(text = description, style = MaterialTheme.typography.bodyLarge)
            Spacer(Modifier.height(24.dp))

            // Add a back button as a central action for clarity
            Button(onClick = { navController.popBackStack() }) {
                Text("Go Back")
            }
        }
    }
}