var
// HTML Document
d = document,
s = d.querySelector("canvas"),
// Canvas context
c = s.getContext("2d"),
// Canvas functions
cv = {
    // Init the canvas
    i()
    {
        s.width = w;
        s.height = h;
    },
    // Parse string to element
    p(e)
    {
        a = e.split(","),
        a.shift()
        return [e[0], a];
    },
    // Draw elements from array
    d(el)
    {
        el.forEach(e=>{
            // Parse element string to arguments
            let [t,a] = cv.p(e);
            console.log(t,a);
            cv[t](...a);
            // using `cv.m` instead of `this.m` to save space
        });
    },
    // Fill style
    // Extracted into own method to save space
    // fc - Hex color value without the `#`
    c(fc)
    {
        c.fillStyle = '#'+fc;
    },
    // Add text
    // tm - message
    // tx, ty - position
    // tf - font size
    // tc - text color
    t(tm,tx,ty,tf,tc)
    {
        cv.c(tc);
        c.font = tf+'px Arial';
        // Adding `to.f` as offset to `ty`
        c.fillText(tm,tx,parseInt(ty)+parseInt(tf));  
    },
    // Draw Rectangle
    // rx, ry - position
    // rw, rh - size
    // rc - color
    r(rx,ry,rw,rh,rc)
    {
        cv.c(rc);
        c.fillRect(rx,ry,rw,rh);
    },
    // Grid snapper
    g(gx,gy,gs,gc)
    {
        console.log(gx,gy,gs,gc);
    }
};