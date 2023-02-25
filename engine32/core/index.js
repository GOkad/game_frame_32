/**
 * I am using Classes instead of 
 * functions in order to save space
 * by not using the `function` keyword
 */

class E32Core
{
    constructor()
    {
        console.log(`E32Core.${env.version}`);

        this.screen = new Screen();
        /**
         * !- DEBUG ONLY -!
         */
        this.debug();
        
        this.begin_polling();
        // this.screen.demo();
    }

    begin_polling()
    {
        setInterval(()=>{
            console.log("poll");
            /**
             * Fetch data from url
             */
            this.screen.demo();
        }, env.poll_interval);
    }

    /**
     * !- DEBUG ONLY -!
     * Add all debugging methods, tests, etc.
     */
    debug()
    {
        if (env.dev_refresh)
        {
            setInterval(()=>location.reload(), env.dev_refresh);
        }
    }
}
const e32Core = new E32Core();