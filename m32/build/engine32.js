console.log("Engine32");
var 
// Window height
h=window.innerHeight,
// Window width
w=window.innerWidth,
// HTML Document
d=document,
// Canvas Element
s=d.querySelector("canvas"),
// Canvas context
c=s.getContext("2d"),
m = Math,
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
        setInterval(()=>{
            f.rq(`/sbuf`,(el)=>{

                if(cf.c)
                {
                    f.r(0,0,w,h,'000');
                }

                f.d(el);
            })
        },cf.r);
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
            f[t](...a);
            // using `cv.m` instead of `this.m` to save space
        });
    },
    // Fill style
    // Extracted into own method to save space
    // fc - Hex color value without the `#`
    fs(fc)
    {
        c.fillStyle = '#'+fc;
    },
    // Stoke style
    // sc - Hex color value without the `#`
    ss(sc)
    {
        c.strokeStyle = "#"+sc;
    },
    // Fill Gradient
    // TODO: implement
    gr()
    {

    },
    // Set line width
    lw(wd)
    {
        c.lineWidth=wd;
    },
    // Add text
    // tm - message
    // tx, ty - position
    // tf - font size
    // tc - text color
    t(tm,tx,ty,tf,tc)
    {
        f.fs(tc);
        c.font = tf+'px Arial';
        // Adding `to.f` as offset to `ty`
        c.fillText(tm,tx,parseInt(ty)+parseInt(tf));  
    },
    // Draw line
    // lx, ly - line start
    // lxe, lye - line end
    // lc - line color
    // lw - line width; def=1
    l(lx,ly,lxe,lye,lc,lw=1)
    {
        c.moveTo(lx, ly);
        c.lineTo(lxe, lye);
        f.ss(lc);
        f.lw(lw);
        c.stroke();
    },
    // Draw Rectangle
    // rx, ry - position
    // rw, rh - size
    // rc - color
    r(rx,ry,rw,rh,rc)
    {
        f.fs(rc);
        c.fillRect(rx,ry,rw,rh);
    },
    // Draw circle
    // TODO: Enchance to support `arc` element
    // cx, cy - position
    // cr - circle Radius
    // ca - start angle
    // cc - color
    // cw - circle stoke sith; def=1
    c(cx,cy,cr,ca,cc,cw=1)
    {
        c.beginPath();
        c.arc(cx, cy, cr, ca, 2*m.PI);
        f.fs(cc);
        c.fill();
        f.lw(cw);
        c.stroke();
    }
};

f.m();