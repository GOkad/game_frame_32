/**
 * Mock ESP32 Fetch requests
 */

var mock32 = {
    parseURL(url_string)
    {
        url = url_string.split("?");
        params = {};
        if (url.length == 2) {
            url[1].split("&").forEach(param => {
                const pair = param.split("=");
                params[pair[0]] = pair[1];
            });
        }
        return [url[0], params];
    },
    request(url_string, callback)
    {
        const [url, params] = this.parseURL(url_string);
        switch(url)
        {
            case "/init":
                this.init(params, callback);
                break;
            case "/sbuf":
                this.read_sbuf(params, callback);
                break;
            default:
                console.error("Undefined endpoint"+url);
        }
    },
    init(params, callback)
    {
        const w = parseInt(params.w);
        const h = parseInt(params.h);
        console.log(w, h);

        return {

        };
    },
    read_sbuf(params, callback)
    {
        callback([
            ...this.grid(),
            this.grid_snapper(),
            ...this.text(),
        ]);
    },
    // Demo functions
    text()
    {
        let y_offset = 0;
        let sbuf = [];
    
        for(let i=0; i <= 65; i += 5) {;

            let
            tm = `f${i}-${Math.floor((w/i)*2)} chars max`,
            tx = 5,
            ty = i+y_offset,
            tf = i,
            tc = 'f00';

            sbuf.push(
                `t,${tm},${tx},${ty},${tf},${tc}`
            );
            
            y_offset += i;
        }

        return sbuf;
    },

    get_grid_values()
    {
        const 
        cell = 30,
        grid_h = Math.floor(h/cell),
        grid_w = Math.floor(w/cell),
        y_offset = (h-(grid_h*cell))/2,
        x_offset = (w-(grid_w*cell))/2;

        return {cell, grid_h, grid_w, x_offset, y_offset};
    },
    grid()
    {
        let {cell, grid_h, grid_w, x_offset, y_offset} = this.get_grid_values();
        let sbuf = [];
        for(let y = 0; y < grid_h; y++)
        {
            let flag = ( y%2 == 0 );
            for(let x = 0; x < grid_w; x++)
            {
                flag = !flag;
                let
                rx = (x*cell)+x_offset,
                ry = (y*cell)+y_offset,
                rw = cell,
                rh = cell,
                rc = flag ? 'fff' : 'ececec'
                ;
                sbuf.push(
                    `r,${rx},${ry},${rw},${rh},${rc}`
                );
            }
        }

        return sbuf;
    },
    snapper: {
        x: 0,
        y: 0,
        size: 1.5,
        move(dir,grid_h,grid_w,){
            this.x++;
            if(this.x >= grid_w)
            {
                this.x = 0;
                this.y++;
            }
            if(this.y >= grid_h)
            {
                this.y = 0;
            }
        }
    },
    grid_snapper()
    {
        let {
            cell,
            grid_h,
            grid_w,
            x_offset,
            y_offset
        } = this.get_grid_values();

        let snpr = this.snapper;
        snpr.move(null, grid_h,grid_w)

        let
            gs = cell/snpr.size,
            // Grid offset
            go = ((cell-gs)/2),
            gx = (snpr.x*cell)+x_offset+go,
            gy = (snpr.y*cell)+y_offset+go,
            gc = 'f0f';

        return `r,${gx},${gy},${gs},${gs},${gc}`;
    }
};