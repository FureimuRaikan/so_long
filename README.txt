_________________________________________________________________________________
|                                                                               |
|-------------------------SO_LONG instructions for use--------------------------|
|_______________________________________________________________________________|
|                                                                               |
|                                                                               |
|    Rules:                                                                     |
|                                                                               |
|    The player must collect all items in the least amount of moves before      |
|    being granted access to the exit.                                          |
|                                                                               |
|    To move, use the arrows or WASD keys.                                      |
|    To quit, press Escape or 'Q' or click on the Close window icon.            |
|                                                                               |
|_______________________________________________________________________________|
|                                                                               |
|    Usage: ./so_long map.ber                                                   |
|_______________________________________________________________________________|
|                                                                               |
|                                                                               |
|-------------------------------MAP RULES---------------------------------------|
|                                                                               |
|    Map must be a .ber file.                                                   |
|                                                                               |
|    Map must be rectangular and surrounded by walls.                           |
|                                                                               |
|    Both Exit and Collectibles must be reachable by the player.                |
|                                                                               |
|    Map must only contain 0,1,P,E,C or X (bonus only) where:                   |
|    0 represents an empty tile.                                                |
|    1 represents a wall.                                                       |
|    P represents the starting position of the player. (P must be unique)       |
|    E represents the exit position. (E must be unique)                         |
|    C represents the collectibles (items) position(s). (At least 1 C)          |
|   *X represents an ennemy patrol. (bonus)                                     |
|                                                                               |
|                                                                               |
|                                                                               |
|                                                                               |
|    Map exemples :                                                             |
|                                                                               |
|        1111111111111           1111111111111111111111111111111111             |
|        10010000000C1           1E0000000000000C00000C000000000001             |
|        1000011111001           1010010100100000101001000000010101             |
|        1P0011E000001           1010010010101010001001000000010101             |
|        1111111111111           1P0000000C00C0000000000000000000C1             |
|                                1111111111111111111111111111111111             |
|                                                                               |
|                                                                               |
|_______________________________________________________________________________|
