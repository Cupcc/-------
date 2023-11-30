import requests
import json

apiUrl = ' https://chatapi.onechat.fun/v1/chat/completions'
apiKey = 'sk-6yJ5qOik53kgvuEU87Ba522aEe134a95962f4b171a55273f'
temperature = 1.0
max_tokens = 600
model = 'gpt-4'

headers = {
    'Accept': 'application/json',
    'Content-Type': 'application/json',
    'Authorization': 'Bearer ' + apiKey
}

post = {
    'model': model,

    'max_tokens': max_tokens,
    'temperature': temperature,
    'messages': [
        {
            'role': 'system',
            'content': '请输入你的提示信息'
        },
        {
            'role': 'user',
            'content': '鲁迅和周树人是什么关系'
        }
    ]
}


try:
    response = requests.post(
        apiUrl,
        headers=headers,
        data=json.dumps(post),
        timeout=None
    )
    print(f"Response status code: {response.status_code}")

    if response.status_code == 200:
        if response.text:
            print(response.json())
        else:
            print("The response is empty.")
    else:
        print(f"Request failed, response content: {response.text}")
except Exception as e:
    print('Error:', e)