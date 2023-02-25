/**
 * Screen
 * 
 * using `env.symbols` because it's one char
 * shorter than `this.symbols`
 */

class Screen
{
    constructor()
    {
        this.element = document.querySelector("canvas");
    }

    clear()
    {
    }

    write(message)
    {
        var ctx = this.element.getContext("2d");
        ctx.font = "30px Arial";
        ctx.fillText(message, 10, 50);
    }

    test()
    {

    }
}