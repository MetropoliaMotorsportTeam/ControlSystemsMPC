# Get nose position from outer skin (length of the full vehicle)
set nosePos [lindex [IFileRead Vehicle Vehicle.OuterSkin] 3]

# Start Position is 0.3m from the start line
set refPos [expr {3.5 - $nosePos - 0.3}]

NamedValue set Start_Position $refPos

# Log Reference Position in the Session Log
SessionLogMsg $refPos
