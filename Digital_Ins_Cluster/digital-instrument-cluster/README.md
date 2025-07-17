# Digital Instrument Cluster Simulator

This project is a desktop application that simulates a digital instrument cluster for vehicles, including a speedometer, RPM gauge, fuel indicator, and various warning lights. The application is built using Qt6/QML and C++, and it interfaces with a CAN simulator to receive real-time data.

## Features

- **Speedometer**: Displays the current speed of the vehicle.
- **RPM Gauge**: Shows the engine RPM.
- **Fuel Indicator**: Monitors and displays the fuel level.
- **Turn Indicators**: Visual indicators for left and right turns.
- **Low Fuel Warning**: Alerts the user when fuel levels are low.
- **Emergency Warning Lights**: Provides visual alerts for emergency situations.

## Tools Used

- **Qt6/QML**: Framework for building the user interface.
- **C++**: Programming language for application logic.
- **CAN Simulator**: Simulates CAN messages for speed, RPM, and fuel level (can use Python-CAN or socketCAN mock).

## Setup Instructions

1. **Clone the Repository**:
   ```
   git clone <repository-url>
   cd digital-instrument-cluster
   ```

2. **Install Dependencies**:
   Ensure you have Qt6 installed on your system. You can download it from the [Qt website](https://www.qt.io/download).

3. **Build the Project**:
   Use CMake to configure and build the project:
   ```
   mkdir build
   cd build
   cmake ..
   make
   ```

4. **Run the Application**:
   After building, you can run the application:
   ```
   ./digital-instrument-cluster
   ```

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue for any enhancements or bug fixes.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.