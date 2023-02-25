/**
 * ENV Variables file
 * 
 * I use `env` variables because 
 * `env.var`  [min: e.v]    is shortart than
 * `this.var` [min: this.v] and we save more space
 * 
 * also using one Object to avoid 
 * multiple usage of `var` and symbols ( ={}; )
 * var object = {key:value}; var object2 = {key:value}
 * var object = {key:value,key:value};
 */
var env = {
    version: "v0.0.1",
    
    /**
     * Location refresh interval
     * !- DEBUG ONLY -!
     * false - off
     * int (ms)
     */
    dev_refresh: false,
    
    /**
     * Send event request
     * polling interval
     */
    poll_interval: 500,

    /**
     * Window inner width
     */
    width: 0,
    /**
     * Window inner height
     */
    height: 0,

    /**
     * Main grid cell size [width|height]
     */
    grid_size: 30,
    /**
     * Defualt Font size
     */
    font_size: 15,
    /**
     * Maximum symbols on screen.
     * Calculated in Screen.constructor()
     */
    max_symbols: 0,
    /**
     * Symbols
     */
    nl: "\n",

    /**
     * Colors
     */
    black: "#000",
    white: "#fff",
    red: "#f00",
    green: "#0f0",
    yellow: "#ff0"
};