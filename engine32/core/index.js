/**
 * I am using Classes instead of 
 * functions in order to save space
 * by not using the `function` keyword
 */

class E32Core
{
    constructor()
    {
        this.screen = new Screen();
        /**
         * !- DEBUG ONLY -!
         */
        this.debug();
        
        this.init_event_loop();
        console.log(`E32Core.${env.version}`);
    }

    init_event_loop()
    {
        setInterval(()=>{
            console.log("event");
            this.screen.clear();
            this.screen.write("Hello E32Core"+Math.random());
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