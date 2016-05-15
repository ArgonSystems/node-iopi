var Timer = require("nanotimer");
var iopi = require("../index");
var timer=new Timer();
class Button{
  constructor(bus,pin,onPress){
    this.bus=bus;
    this.pin=pin;
    this.onPress=onPress;
    iopi.init(bus);
    iopi.setPinDirection(this.bus,this.pin,1);
    timer.setTimeout(this._read.bind(this),'','50m');
    this._value=0;
  }
  _read(){
    var value=iopi.readPin(this.bus,this.pin);
    if(value && !this._value && typeof this.onPress == "function"){
      this.onPress();
    }
    timer.setTimeout(this._read.bind(this),'','50m');
  }
}
module.exports=Button;
