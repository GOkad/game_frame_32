console.log("Engine32");
var 
// Window height
h=window.innerHeight,
// Window width
w=window.innerWidth,
// HTML Document
d=document,
s=d.querySelector("canvas"),
// Canvas context
c=s.getContext("2d"),

// - using Object to define all functions
// to save space from `function` keyword and 
// `this.` if using class;
// - using `f.m()` and not `this.m()` to save space;
f={
    // Request function
    // ur - URL + url params
    // cd - on success callback
    rq(ur,cb)
    {
        mock32.request(ur,cb);
        // fetch(ur)
        // .then(rq=>rq.json())
        // .then(dt=>cb(dt))
        // .catch(e=>alert(e.message));
    },
    // main()
    m()
    {
        // Initiate Canvas
        s.width = w;
        s.height = h;
        f.rq("/cfg?w="+w+"&h="+h,(cf)=>{
            f.i(cf)
        })
    },
    // Init engine and start `/sbuf` read loop
    i(cf){
        console.log(cf);
        // [DEBUG ONLY]
        console.log(cf);
        setInterval(()=>{
            f.req(`/sbuf`,(el)=>{
                f.d(el);
            })
        },1000/2);
    },
    // [ Canvas Functionalty ]
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
            let [t,a] = f.p(e);
            console.log(t,a);
            f[t](...a);
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
        f.c(tc);
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
        f.c(rc);
        c.fillRect(rx,ry,rw,rh);
    },
    // Grid snapper
    g(gx,gy,gs,gc)
    {
        console.log(gx,gy,gs,gc);
    }
};

f.m();