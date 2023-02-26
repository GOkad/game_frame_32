/**
 * @file Engine32.h
 * Minified version of the JavaScript engine.
 * Copy this file into "../include/core/m32.h"
 * 
 * 
 * @date 2023-02-26
 * Last minified version of m32
 * version: 0.2.0
 * size:    -- MINIFY FIRST --
 * 
 */

const char* m32 PROGMEM = R"(
<!DOCTYPE html>
<html>
    <head>
        <meta name="viewport" content="width=device-width, initial-scale=1" />
        <style>*{padding:0;margin:0;}body{overflow: hidden;background:#222;}canvas{position: fixed;top:0;left:0;}</style>
    </head>
    <body>
        <canvas></canvas>
        <script type="text/javascript">
var h=window.innerHeight,w=window.innerWidth,d=document,s=d.querySelector("canvas"),c=s.getContext("2d"),
f={
rq(ur,cb){fetch(ur).then(rq=>rq.json()).then(dt=>cb(dt)).catch(e=>alert(e.message))},
m(){s.width=w;s.height=h;f.rq("/cfg?w="+w+"&h="+h,(cf)=>{f.i(cf)})},
i(cf){console.log(cf);setInterval(()=>{f.req(`/sbuf`,(el)=>{f.d(el);})},1000/2)},
p(e){a=e.split(","),a.shift();return [e[0], a]},
d(el){el.forEach(e=>{let [t,a]=f.p(e);console.log(t,a);f[t](...a)})},
c(fc){c.fillStyle='#'+fc;},
t(tm,tx,ty,tf,tc){f.c(tc);c.font = tf+'px Arial';c.fillText(tm,tx,parseInt(ty)+parseInt(tf));},
r(rx,ry,rw,rh,rc){f.c(rc);c.fillRect(rx,ry,rw,rh);}
};
f.m();
        </script>
    </body>
</html>
)";