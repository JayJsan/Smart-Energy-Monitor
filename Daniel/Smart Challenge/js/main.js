// UI elements.
const deviceNameLabel = document.getElementById('device-name');
const connectButton = document.getElementById('connect');
const disconnectButton = document.getElementById('disconnect');
// const terminalContainer = document.getElementById('terminal');
const sendForm = document.getElementById('send-form');
const inputField = document.getElementById('input');

// Helpers.
const defaultDeviceName = "Team 13 Smart Energy";
// const terminalAutoScrollingLimit = terminalContainer.offsetHeight / 2;
// let isTerminalAutoScrolling = true;

// const scrollElement = (element) => {
//   const scrollTop = element.scrollHeight - element.offsetHeight;

//   if (scrollTop > 0) {
//     element.scrollTop = scrollTop;
//   }
// };


// Obtain configured instance.
const terminal = new BluetoothTerminal();

// Override `receive` method to log incoming data to the terminal.
terminal.receive = function(data) {
  //console.log(data);
  manipulateValues(data);
};

//Override default log method to output messages to the terminal and console.
// terminal._log = function(...messages) {
//   // We can't use `super._log()` here.
//   messages.forEach((message) => {
//     console.log(message); // eslint-disable-line no-console
//   });
// };





// Bind event listeners to the UI elements.
connectButton.addEventListener('click', () => {
  terminal.connect().
      then(() => {
        deviceNameLabel.textContent = "Team 13 Smart Energy, Connected";
      });
});

disconnectButton.addEventListener('click', () => {
  terminal.disconnect();
  deviceNameLabel.textContent = "Team 13 Smart Energy";
});

// sendForm.addEventListener('submit', (event) => {
//   event.preventDefault();

//   send(inputField.value);

//   inputField.value = '';
//   inputField.focus();
// });

// Switch terminal auto scrolling if it scrolls out of bottom.
// terminalContainer.addEventListener('scroll', () => {
//   const scrollTopOffset = terminalContainer.scrollHeight -
//       terminalContainer.offsetHeight - terminalAutoScrollingLimit;

//   isTerminalAutoScrolling = (scrollTopOffset < terminalContainer.scrollTop);
// });
