/**
 * m32 minified javascript engine
 * Minified version of the engine.
 * Copy this file into "../include/Engine32.h"
 * 
 * 
 * @date 2023-02-25
 * Last minified version of engine32
 * version: 0.1.0
 * size:    1.25KB
 */

#ifndef M32_ENGINE
#define M32_ENGINE

const char* m32 PROGMEM = R"(
<!DOCTYPE html><html><head><meta name="viewport" content="width=device-width, initial-scale=1"/><style>*{padding:0;margin:0;}body{overflow:hidden;background:#222;}canvas{position:fixed;top:0;left:0;}</style></head><body><canvas></canvas><script type="text/javascript">var h=window.innerHeight,w=window.innerWidth,m=Math,cs=50,gw=m.floor(w/cs),gh=m.floor(h/cs),gxo=0,gyo=0,cx=0,cy=0,crs=cs/2,co=(cs-crs)/2,d=document,s=d.querySelector("canvas"),c=s.getContext("2d"),cl={bl:"#000",w:"#fff",r:"#f00",g:"#0f0",b:"#00f",y:"#ff0",gr:"#a1a1a1"},f=10,cm={r(rx,ry,rw,rh,rc){c.fillStyle=rc;c.fillRect(rx,ry,rw,rh);},t(tx,ty,tm,to={}){to.f=(to.f?to.f:f);c.fillStyle=to.c?to.c:cl.g;c.font=to.f+'px Arial';c.fillText(tm,tx,ty+to.f);},dc(){cm.r(cx*cs+co,cy*cs+co,crs,crs,cl.y)},dg(){for(let gy=0;gy<gh;gy++){let fl=(gy%2==0);for(let gx=0;gx<gw;gx++){fl=!fl;cm.r((gx*cs)+gxo,(gy*cs)+gyo,cs,cs,fl?cl.w:cl.gr);if(gx==cx&&gy==cy){eh.m({x:gx,y:gy});cm.dc()}}}}},eh={m({x,y}){cx=x;cy=y;cm.dc();}};class m32{i(){s.width=w;s.height=h;cm.dg();this.p()}p(){setInterval(()=>{fetch("/events").then(r=>r.json()).then((dt)=>this.e(dt)).catch(e=>alert(e.message));},1000)}e(eb){cm.dg();eb.forEach(ev=>{if(ev.t=='m'){eh.m(ev.p)}});}}var e=new m32();e.i();</script></body></html>
)";

#endif
