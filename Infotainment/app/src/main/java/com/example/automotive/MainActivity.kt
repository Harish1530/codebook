
package com.example.automotive      // <-- keep this the same as the namespace / applicationId

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import com.example.automotive.navigation.AppNavGraph
import androidx.compose.runtime.Composable
import androidx.compose.ui.tooling.preview.Preview

/**
 * --------------------------------------------------------------------
 *  Activity entry point
 * --------------------------------------------------------------------
 */
class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge() // optional – draws behind system bars
        setContent {
            AppNavGraph()
        }
    }
}

/**
 * --------------------------------------------------------------------
 *  Preview – lets you see the whole app in Android Studio
 * --------------------------------------------------------------------
 */
@Preview(showBackground = true)
@Composable
fun AutomotiveAppPreview() {
    AppNavGraph()
}

