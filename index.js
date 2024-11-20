require('dotenv').config(); // Load environment variables
const CSES = require('cses-api').default; // Import the default export
const SubmitOptions = require('cses-api').default;
const fs = require('fs');

async function fetchUser() {
  try {
    const username = process.env.CSES_USERNAME;
    const password = process.env.CSES_PASSWORD;
    if (!username || !password) {
      throw new Error('Please set CSES_USERNAME and CSES_PASSWORD in your .env file');
    }
    const args = process.argv.slice(2);
    const problemId = args[0];

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

    const filePath = `./${problemId}.cpp`;
    if (!fs.existsSync(filePath)) {
      throw new Error(`File not found: ${filePath}`);
    }
    const submitOptions = {task: problemId, lang:"C++", type: "course", target: "problemset", file: fs.createReadStream(filePath) };
    const submitId = await cses.submit(submitOptions);

    var submitStatus = await cses.getSubmitStatus(submitId);
    while (submitStatus != "READY" && submitStatus != "COMPILE ERROR") {
      submitStatus = await cses.getSubmitStatus(submitId);
    } // wait while all test are being run 

    results = {"result": "", "tests": []}
    if (submitStatus == "COMPILE ERROR") {
      testResults["result"] = "COMPILATION ERROR";
      console.log("COMPILATION ERROR");
      return 0;
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
    const jsonString = JSON.stringify(results, null, 2);
    fs.writeFile(`${problemId}.json`, jsonString, (err) => {
      if (err) {
          console.error('Error writing to file', err);
      } else {
          console.log(`Results successfully written to ${problemId}.json`);
      }
    });
  }
  } catch (error) {
    console.error('An error occurred:', error.message);
  }

}

fetchUser();
