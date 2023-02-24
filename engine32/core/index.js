/**
 * I am using Classes instead of 
 * functions in order to save space
 * by not using the `function` keyword
 */

class E32Core
{
    constructor()
    {
        /**
         * !- DEBUG ONLY -!
         */
        this.debug();
        
        console.log(`E32Core.${env.version}`);
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