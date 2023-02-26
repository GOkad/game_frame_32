class m32
{
    // Fetch function
    f(ur,cb)
    {
        fetch(ur)
        .then(r=>r.json())
        .then(dt=>cb(dt))
        .catch(e=>alert(e.message));
    }
    // Init Engine
    i()
    {
        s.width = w;
        s.height = h;
        this.f(`/build?w=${w}&h=${h}`,dt =>{
            {
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
            }
            console.log(dt);
        });
        // this.p();
    }

    // Polling interval
    p()
    {
        // Poll every 1000 ms
        setInterval(()=>{

            // TOOD: Add event polling system
            this.f("/events",dt=>{
                this.e(dt);
            });
        },1000);
    }
    // Parse event
    // eb - event buffer
    e(eb)
    {
        eb.forEach(ev=>{
            console.log(ev);
            eh[ev.t](ev.p)
        });
    }
}

var e = new m32();
e.i();

test_events();