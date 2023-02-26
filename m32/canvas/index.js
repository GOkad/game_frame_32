var 
// Window height
h = window.innerHeight,
// Window width
w = window.innerWidth,
// usin Object to define all functions
// to save space from `function` keyword and 
// `this.` if using class
f = {
    // Request function
    // ur - URL + url params
    // cd - on success callback
    r(ur,cb)
    {
        mock32.request(ur,cb);
        // fetch(ur)
        // .then(rq=>rq.json())
        // .then(dt=>cb(dt))
        // .catch(e=>alert(e.message));
    },
    // main()
    m()
    {
        cv.i();
        setInterval(()=>{
            f.r(`/sbuf`,(dt)=>{
                cv.d(dt);
            })
        }, 1000/5);
    }
}
;

f.m();