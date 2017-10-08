/* 
    Created on : Sep 18, 2017, 6:28:09 PM
    Author     : Head First Javascript Example Project
 */

function View(){
    this.messageArea;
    this.cell;
}

    View.prototype.displayMessage=function(msg) {
        this.messageArea = document.getElementById("messageArea");
        this.messageArea.innerHTML = msg;
    };

    View.prototype.displayHit=function(location) {
        this.cell = document.getElementById(location);
        this.cell.setAttribute("class", "hit");
    };

    View.prototype.displayMiss=function(location) {
        this.cell = document.getElementById(location);
        this.cell.setAttribute("class", "miss");
    };

