/**
 * Script to develop and demo Engine functionality
 */

function demo()
{
    // Clear screen
    cm.r(0, 0, w, h, cl.bl);
    // text_demo();
    dev_grid();
}

function text_demo()
{
    let y_offset = 0;
    
    for(let i=0; i <= 65; i += 5) {
        let max_chars = Math.floor((w/i)*2);
        let message = `f${i}-${max_chars} chars max`;
        cm.t(0, i+y_offset,message,{f:i});
        y_offset += i;
    }
}


function dev_grid()
{
    for(let gy = 0; gy < gh; gy++)
    {
        let flag = ( gy%2 == 0 );
        for(let gx = 0; gx < gw; gx++)
        {
            flag = !flag;
            cm.r(
                (gx*cs)+gxo,
                (gy*cs)+gyo,
                cs,cs,
                flag ? cl.w : cl.gr
            )
            if (gx==cx&&gy==cy)
            {
                eh.m({x:gx, y:gy});
                cm.dc();
            }
        }

    }
}

const events = {
    move_cursor:{
        t: 'm',
        p: {x:0,y:0}
    },
    clone(event)
    {
        return JSON.parse(JSON.stringify(event))
    }
}


function test_events()
{
    // Event buffer
    let ebuf = [
        events.clone(events.move_cursor)
    ];
    // Loop only once
    const once = false;

    function interval_cb(){
        // console.log(ebuf);
        e.e(ebuf);
        dev_grid();

        ebuf[0].p.x++;
        if(ebuf[0].p.x>=gw)
            {ebuf[0].p.x = 0;
            ebuf[0].p.y++;}

        if (ebuf[0].p.y>=gh)
            {ebuf[0].p.y = 0;}
    }
    
    interval_cb();
    // Mock poll event interval
    let mock_poll = setInterval(() => {
        interval_cb();
    }, 500);

    if ( once )
    {
        clearInterval(mock_poll);
        mock_poll = false;
    }
}