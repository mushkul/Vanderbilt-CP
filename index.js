require('dotenv').config(); // Load environment variables
const CSES = require('cses-api').default; // Import the default export
const SubmitOptions = require('cses-api').default;
const fs = require('fs');
const path = require('path');

function getCppFiles(dir) {
  try {
      const files = fs.readdirSync(dir); // Read all files in the directory
      const cppFiles = files
          .filter(file => {
              const ext = path.extname(file);
              const baseName = path.basename(file, '.cpp');

              // Check if the file is a .cpp file
              if (ext === '.cpp') {
                  const jsonFilePath = path.join(dir, `${baseName}.json`);

                  // Exclude the .cpp file if a corresponding .json file exists
                  return !fs.existsSync(jsonFilePath);
              }
              return false;
          })
          .map(file => path.join(dir, file)); // Get full paths of the .cpp files

      return cppFiles;
  } catch (err) {
      console.error('Error reading directory:', err);
      return [];
  }
}

async function fetchUser() {
  try {
    const username = process.env.CSES_USERNAME;
    const password = process.env.CSES_PASSWORD;
    if (!username || !password) {
      throw new Error('Please set CSES_USERNAME and CSES_PASSWORD in your .env file');
    }
    const args = process.argv.slice(2);
    var solutionPath = args[0];
    files = [];
    if (!solutionPath.endsWith('.cpp')) {
      files = getCppFiles(solutionPath);
    }
    else {
      files = [solutionPath];
    }

    // Step 1: Login and get tokens
    console.log('Logging in...');
    const user = await CSES.getUser(username, password);
    if (!user) {
      console.error('Login failed: Invalid credentials or server issue');
      return;
    }
    console.log(`Logged in as ${user.name} (ID: ${user.id})`);
    // Step 2: Initialize CSES instance with tokens
    const cses = new CSES({ php: user.php, csrf: user.csrf });


    for (var i = 0; i < files.length; i++) {
      // console.log(files[i]);
    solutionPath = files[i];
    const outputPath = solutionPath.replace(/\.cpp$/, '.json');
    const fileNameWithExtension = solutionPath.split('/').pop(); // Get the last part: "124.cpp"

    // Split by '.' to separate the number and extension
    const parts = fileNameWithExtension.split('.');
    const problemId = parts[0]; // The numeric part before the extension

    console.log("Extracted ID:", problemId); // Output: 124

    // const filePath = `./${problemId}.cpp`;
    if (!fs.existsSync(solutionPath)) {
      throw new Error(`File not found: ${solutionPath}`);
    }
    const submitOptions = {task: problemId, lang:"C++", option:"C++20", type: "course", target: "problemset", file: fs.createReadStream(solutionPath) };
    const submitId = await cses.submit(submitOptions);

    var submitStatus = await cses.getSubmitStatus(submitId);
    while (submitStatus != "READY" && submitStatus != "COMPILE ERROR") {
      submitStatus = await cses.getSubmitStatus(submitId);
    } // wait while all test are being run 

    results = {"result": "", "tests": []}
    if (submitStatus == "COMPILE ERROR") {
      console.log(submitStatus)
      results["result"] = "COMPILE ERROR";
    }
    else {
    // tests are completed
    const testResults = await cses.getSubmitResults(submitId);
    var verdict = "ACCEPTED";
    for (const testResult of testResults) {
        if (testResult.verdict != "ACCEPTED") {
          verdict = testResult.verdict;
          break;
        }
    }

    results["result"] = verdict;
    results["tests"] = testResults;
  }
    const jsonString = JSON.stringify(results, null, 2);
    fs.writeFile(`${outputPath}`, jsonString, (err) => {
      if (err) {
          console.error('Error writing to file', err);
      } else {
          console.log(`Results successfully written to ${problemId}.json`);
      }
    });
  }
}
  catch (error) {
    console.error('An error occurred:', error.message);
  }

}

fetchUser();
// getCppFiles("./solutions/gpt-4o");
// fetchUser();
