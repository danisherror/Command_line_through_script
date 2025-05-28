const { exec } = require('child_process');

function runCommand(cmd) {
  exec(cmd, (error, stdout, stderr) => {
    if (error) {
      console.log(`Error running "${cmd}": ${error.message}`);
      return;
    }
    if (stderr) {
      console.log(`stderr from "${cmd}": ${stderr}`);
      return;
    }
    console.log(`Output from "${cmd}":\n${stdout}`);
  });
}

runCommand("ls");
