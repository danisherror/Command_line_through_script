import subprocess

def execCommand(cmd_list):
    result = subprocess.run(cmd_list, capture_output=True, text=True)
    return result.stdout

print("Current directory:\n", execCommand(['pwd']))
print("File list:\n", execCommand(['ls', '-ltrh']))
