var
// [--System Variables--]
// ESP32 IP
ip = "http://192.168.0.4/",
// Window height
h = window.innerHeight,
// Window width
w = window.innerWidth,
// JS Math Library
m = Math,
// System Grid
    // Cell size
    // 15?
    cs = 50,
    // Grid width [normalized for cursor x]
    gw = m.floor(w/cs);
    // Grid height [normalized for cursor y]
    gh = m.floor(h/cs);
    // Grid X offset
    gxo = 0,
    // Grid Y offset
    gyo = 0,
// Cursor
    // X postition
    cx = 0,
    // Y postition
    cy = 0,
    // Cursor size
    crs = cs/2,
    co = (cs-crs)/2
    
// [--JS Variables--]
// HTML Document
d = document,
// Canvas element
s = d.querySelector("canvas"),
// Canvas context
c = s.getContext("2d"),
// Colors
cl = {
    bl: "#000",
    w: "#fff",
    r: "#f00",
    g: "#0f0",
    b: "#00f",
    y: "#ff0",
    gr: "#a1a1a1"
},
// Default font size
f = 10,
// Components
cm = {
    // Draw Rectangle
    // rx, ry - position
    // rw, rh - size
    // rc - color
    r(rx,ry,rw,rh,rc)
    {
        c.fillStyle = rc;
        c.fillRect(rx,ry,rw,rh);
    },
    // Add Text to screen
    // tx, ty - position
    // tm - Text message
    // to? = {f: <font_size>, c: <color>}
    t(tx,ty,tm,to={})
    {
        // Set font if missing
        to.f = (to.f ? to.f : f);
        c.fillStyle = to.c ? to.c : cl.g ;
        c.font = to.f+'px Arial';
        // Adding `to.f` as offset to `ty`
        c.fillText(tm,tx,ty+to.f);
    },
    // Draw cursor
    // nx, ny - Cursor position
    dc()
    {
        cm.r(
            cx*cs+co, cy*cs+co,
            crs, crs,cl.y
        )
    }
},
// Event handler
eh = {
    // Move cursor to location
    m({x,y})
    {
        cx = x; cy = y;
        cm.dc();
    }
}
;