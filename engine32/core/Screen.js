/**
 * Screen
 */
var scrn = document.querySelector("canvas");
var context = scrn.getContext("2d");
var cursor = {
    x: 0,
    y: 0,
    size: 0,
    offset:5
};

class Screen
{
    constructor()
    {
        // Calculations
        env.width = window.innerWidth;
        env.height = window.innerHeight;
        env.max_symbols = Math.floor((env.width/env.font_size) * 2);

        // Set canvas size
        scrn.width = env.width;
        scrn.height = env.height;

        // Cursor param calculation
        cursor.size = env.grid_size/2;
        cursor.offset = (env.grid_size-cursor.size)/2;
    }

    clear()
    {
        context.fillStyle = env.black;
        context.fillRect(0, 0, env.width, env.height);
    }
    
    write(message,x,y,color = env.white, font_size = env.font_size)
    {
        /**
         * Max width = 32
         */
        context.fillStyle = color;
        context.font = font_size+"px Arial";
        /**
         * `font_size` is added to `y` as an offset
         */
        context.fillText(message, x, y+font_size);
    }

    rect(x,y,w,h, color = env.black)
    {
        context.fillStyle = color;
        context.fillRect(x, y, w, h);
    }

    move_cursor(x,y)
    {
        cursor.x = x;
        cursor.y = y;

        console.log( cursor );
        this.rect(
            (x*env.grid_size)+cursor.offset,
            (y*env.grid_size)+cursor.offset,
            cursor.size, cursor.size,
            env.yellow
        );
    }
    /**
     * !- DEVELOPMENT ONLY -!
     * 
     * TODO: To be extracted to separate file
     */
    demo()
    {
        this.clear();
        // this.text_demo();
        this.grid_demo();
    }

    grid_demo()
    {

        cursor.x++;
        if ( cursor.x >= (env.width/env.grid_size)-1 )
        {
            cursor.x = 0;
            cursor.y++;
        }
        if ( cursor.y >= (env.height/env.grid_size)-1 )
        {
            cursor.y = 0;
        }

        for(let y = 0; y < env.height/env.grid_size; y++) {
            let flag = ( y%2 == 0 );
            for(let x = 0; x < env.width/env.grid_size; x++)
            {
                flag = !flag;
                let color = flag ? env.white : env.grey;
                
                this.rect(
                    x*env.grid_size, y*env.grid_size,
                    env.grid_size   , env.grid_size,
                    color
                );
                
                if(x == cursor.x && y == cursor.y)
                    this.move_cursor(x, y);
            }
        }
    }

    text_demo()
    {
        let y_offset = 0;
        for(let i = 10; i <= 65; i+=5)
        {
            let max_chars = Math.floor((env.width/i)*2);
            this.write(
                `f${i}-${max_chars} chars max`,
                0, y_offset, env.white,
                i
            );
            y_offset += i;
        }
    }
    
}