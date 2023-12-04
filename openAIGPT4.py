from openai import OpenAI

apiUrl = 'https://ssapi.onechat.shop/v1'
apiKey = 'sk-j0lQuKMEF3UlB9Hu1e9aAc6d661e47D28b96E7Dd2aFc801b'

# openai.api_base = apiUrl
# openai.api_key = apiKey
# prompt = "python3 使用request库调用chatgpt api,如何实现stream output in console"
prompt = "翻译一下：文件描述符"

model = "gpt-4-1106-preview"

client = OpenAI(
    api_key=apiKey,
    base_url=apiUrl,
)

stream = client.chat.completions.create(
    messages=[
        {
            "role":
            "system",
            "content":
            "You act as an embedded development expert who helps me to build programs."
        },
        {
            "role": "user",
            "content": prompt
        },
    ],
    model=model,
    stream=True,
)
print(next(stream))
if stream:
    for chunk in stream:
        if chunk.choices[0].delta.content is not None:
            print(chunk.choices[0].delta.content, end="", flush=True)
else:
    print("Failed to request.")
