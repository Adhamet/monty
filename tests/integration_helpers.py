import os
import subprocess
import difflib
import re
import inspect

def run_test(file):
    filename = os.path.basename(inspect.stack()[1].filename)

    # run your compiled monty executable and capture its output
    monty_process = subprocess.run(["./build/monty", file], capture_output=True, text=True)
    monty_output = monty_process.stdout
    monty_stderr = monty_process.stderr

    # run correct monty implementation and capture its output
    cmonty_process = subprocess.run(["./tests/monty", file], capture_output=True, text=True)
    cmonty_output = cmonty_process.stdout
    cmonty_stderr = cmonty_process.stderr

    # compare the output of your program and correct implementation
    out, err = difflib.SequenceMatcher(None, monty_output, cmonty_output), difflib.SequenceMatcher(None, monty_stderr, cmonty_stderr)
    if out.ratio() == 1 and err.ratio() == 1 and monty_process.returncode == cmonty_process.returncode:
        print(f"integration test {filename} - {file.split('/')[-1]} passed!")
    else:
        print(f"integration test {filename} - {file.split('/')[-1]} failed.")
        if err.ratio() != 1:
            print(f"stderr is different")
            print("current error: \n", monty_stderr)
            print("correct error: \n", cmonty_stderr)
            dif = difflib.Differ()
            monty_diff = dif.compare(monty_stderr.splitlines(), cmonty_stderr.splitlines())
            print("\n".join(monty_diff))
        if out.ratio() != 1:
            print(f"stdout is different")
            print("current output: \n", monty_output)
            print("correct output: \n", cmonty_output)
            dif = difflib.Differ()
            monty_diff = dif.compare(monty_output.splitlines(), cmonty_output.splitlines())
            print("\n".join(monty_diff))
        if monty_process.returncode != cmonty_process.returncode:
            print(f"exit status is different")
            print(f"current exit code: {monty_process}")
            print(f"correct exit code: {cmonty_process}")

def run_manual_test(file, correct_output, correct_error, correct_exit_code):
    filename = os.path.basename(inspect.stack()[1].filename)

    # run your compiled monty executable and capture its output
    monty_process = subprocess.run(["./build/monty", file], capture_output=True, text=True)
    monty_output = monty_process.stdout.strip()
    monty_stderr = monty_process.stderr.strip()

    # run correct monty implementation and capture its output
    cmonty_output = correct_output.strip()
    cmonty_stderr = correct_error.strip()

    # compare the output of your program and correct implementation
    out, err = difflib.SequenceMatcher(None, monty_output, cmonty_output), difflib.SequenceMatcher(None, monty_stderr, cmonty_stderr)
    if out.ratio() == 1 and err.ratio() == 1 and monty_process.returncode == correct_exit_code:
        print(f"integration test {filename} - {file.split('/')[-1]} passed!")
    else:
        print(f"integration test {filename} - {file.split('/')[-1]} failed.")
        if err.ratio() != 1:
            print(f"stderr is different")
            print("current error: \n", monty_stderr)
            print("correct error: \n", cmonty_stderr)
            dif = difflib.Differ()
            monty_diff = dif.compare(monty_stderr.splitlines(), cmonty_stderr.splitlines())
            print("\n".join(monty_diff))
        if out.ratio() != 1:
            print(f"stdout is different")
            print("current output: \n", monty_output)
            print("correct output: \n", cmonty_output)
            dif = difflib.Differ()
            monty_diff = dif.compare(monty_output.splitlines(), cmonty_output.splitlines())
            print("\n".join(monty_diff))
        if monty_process.returncode != correct_exit_code:
            print(f"exit status is different")
            print(f"current exit code: {monty_process.returncode}")
            print(f"correct exit code: {correct_exit_code}")
