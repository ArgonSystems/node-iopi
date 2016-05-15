var PhotoSensor=require("./photo-sensor");
var sensor=new PhotoSensor(0x20,1,function(value){
  console.log(value);
});
