var Timer = require("nanotimer");
var iopi = require("../index");
var timer=new Timer();
class PhotoSensor{
  constructor(bus,pin,onChange){
    this.bus=bus;
    this.pin=pin;
    this.onChange=onChange;
    iopi.init(bus);
    iopi.setPinDirection(this.bus,this.pin,1);
    iopi.setPinPullup(this.bus, this.pin, 1);
    iopi.invertPin(this.bus, this.pin, 1);
    timer.setTimeout(this._read.bind(this),'','50m');
    this._value=0;
  }
  _read(){
    var value=iopi.readPin(this.bus,this.pin);
    if(value != this._value && typeof this.onChange == "function"){
      this.onChange(value);
    }
    this._value=value;
    timer.setTimeout(this._read.bind(this),'','50m');
  }
}
module.exports=PhotoSensor;
