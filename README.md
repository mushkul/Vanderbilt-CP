# Vanderbilt-CP

## Initial setup

```bash
python -m venv ./venv
source venv/bin activate
pip install -r requirements.txt
```

### Generate problems in json format

Commands to run

```bash
python problem_list.py
python generator.py
```

Generated files should appear in problemset directory

# get problem solution based on llm model

```bash
python submit_ai.py <model name>
```

# submit all problem solutions from <model> directory to cset

```bash
node index.js <path to model directory>
```
