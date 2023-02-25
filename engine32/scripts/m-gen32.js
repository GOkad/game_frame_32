class m32
{
    // Init Engine
    i()
    {
        s.width = w;
        s.height = h;
        // this.p();
    }

    // Polling interval
    p()
    {
        // Poll every 1000 ms
        setInterval(()=>{

            // TOOD: Add event polling system
            // fetch(ip+"/events")
            // .then(r=>r.json())
            // .then((dt)=>{
                this.e(dt);
                demo();
            // })
            // .catch(e=>alert(e.message));
        },1000);
    }
    // Parse event
    // eb - event buffer
    e(eb)
    {
        eb.forEach(ev=>{
            // Using `if` statements instead of `switch` to save space
            // Switch statement for ref:
            // switch(ev.t){case 'x':eh.x(ev.p);break;}
            if(ev.t=='m'){eh.m(ev.p)}
        });
    }
}

var e = new m32();
e.i();

test_events();