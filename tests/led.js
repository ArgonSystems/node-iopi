var iopi = require("../index");
class LED{
  constructor(bus,channels){
    iopi.init(bus);
    this.bus=bus;
    this.channels=channels;
  }
  close(){
    for(let x in this.channels){
      this.closeChannel(x);
    }
  }
  open(){
    for(let x in this.channels){
      this.openChannel(x);
    }
  }
  openChannel(channel){
    iopi.setPinDirection(this.bus,this.channels[channel],0);
    iopi.writePin(this.bus, this.channels[channel], 1);
  }
  closeChannel(channel){
    iopi.setPinDirection(this.bus,this.channels[channel],0);
    iopi.writePin(this.bus, this.channels[channel], 0);
  }
}
module.exports=LED;
