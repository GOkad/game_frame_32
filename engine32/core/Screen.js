/**
 * Screen
 * 
 * using `env.symbols` because it's one char
 * shorter than `this.symbols`
 * 
 * using `scrn` because it's shortar than `this.e`
 * using `var` because it's shortar than `const`
 */
var scrn = document.querySelector("canvas");
var ctx = scrn.getContext("2d");

class Screen
{
    constructor()
    {
        env.width = window.innerWidth;
        env.height = window.innerHeight;
        env.font = 20;

        scrn.width = env.width;
        scrn.height = env.height;
    }

    clear()
    {
        ctx.fillStyle = "#000";
        ctx.fillRect(0, 0, env.width, env.height);
    }
    
    write(message)
    {
        ctx.fillStyle = "#fff";
        ctx.font = env.font+"px Arial";
        ctx.fillText(message, 10, 50);
    }

    test()
    {

    }
}