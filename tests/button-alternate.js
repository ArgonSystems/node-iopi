var LED = require("./led");
var Button = require("./button");
var leds=[
  new LED(0x27,{red:1}),
  new LED(0x27,{red:2}),
  new LED(0x27,{red:3}),
  new LED(0x27,{red:4}),
  new LED(0x27,{red:5}),
  new LED(0x27,{red:6}),
  new LED(0x27,{red:7}),
  new LED(0x27,{red:8}),
  new LED(0x27,{red:9}),
  new LED(0x27,{red:10}),
  new LED(0x27,{red:11}),
  new LED(0x27,{red:12}),
  new LED(0x27,{red:13}),
  new LED(0x27,{red:14}),
  new LED(0x27,{red:15}),
  new LED(0x27,{red:16}),
];
process.on('SIGINT', function(){
  for(let x in leds){
    leds[x].close();
  }
  process.exit();
}.bind(null, {exit:true}));
var at=0;
var previous=at;
var next=function(){
  leds[previous].close();
  leds[at].open();
  previous=at;
  at++;
  if(at>=leds.length){
    at=0;
  }
};
var button=new Button(0x21,1,next);
