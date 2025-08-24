file(REMOVE_RECURSE
  "com/digitalinstrumentcluster/src/qml/FuelGauge.qml"
  "com/digitalinstrumentcluster/src/qml/Indicators.qml"
  "com/digitalinstrumentcluster/src/qml/RPMGauge.qml"
  "com/digitalinstrumentcluster/src/qml/Speedometer.qml"
  "com/digitalinstrumentcluster/src/qml/main.qml"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/digital-instrument-cluster_tooling.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
