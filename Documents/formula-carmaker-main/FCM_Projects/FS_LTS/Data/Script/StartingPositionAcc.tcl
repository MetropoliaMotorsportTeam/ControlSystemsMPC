# Get nose position from outer skin (length of the full vehicle)
set nosePos [lindex [IFileRead Vehicle Vehicle.OuterSkin] 3]

#Distance from start of road to start line
set trigger_pos [lindex [IFileRead Road RL.1.Marker.0.Param] 0]

# 0.3m  is the starting distance from the start line
set refPos [expr {$trigger_pos - $nosePos - 0.3}]

# Set NValue Start Position (Scenario Editor)
NamedValue set Start_Position $refPos

# Log Reference Position in the Session Log
SessionLogMsg $refPos
