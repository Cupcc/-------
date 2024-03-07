import anthropic

api_key = "sk-UQpJHKYi68Qn2fj0F8B23c5481F0460981Ac74B66f560317"
api_url = f"https://onechat.fun"


client = anthropic.Anthropic(
  api_key=api_key,
  base_url=api_url
)


with client.messages.stream(
    max_tokens=1024,
    messages=[{"role": "user", "content": "Hello"}],
    model="claude-3-opus-20240229",
) as stream:
  for text in stream.text_stream:
      print(text, end="", flush=True)