# Gemini CLI Commands

This file explains some of the built-in commands available in the Gemini CLI.

## /memory

The `/memory` command is used to display the information that the Gemini agent has stored in its long-term memory. This can include facts, preferences, or other information that the user has explicitly asked the agent to remember.

## /stats

The `/stats` command displays statistics about the current Gemini CLI session. This can include information such as the number of tokens used, the number of tool calls made, and other session-related data.

## /tools

The `/tools` command lists all the available tools that the Gemini agent can use. This includes built-in tools and any custom tools that have been added through the Model Context Protocol (MCP).

## /mcp

The `/mcp` command is used for managing Model Context Protocol (MCP) servers. MCP allows the Gemini CLI to interact with external systems, such as APIs, databases, or custom scripts.

You can use the `/mcp` command to:

*   **List MCP Servers:** See the configured MCP servers and their status.
*   **Add MCP Servers:** Configure a new MCP server.
*   **View Descriptions:** Get detailed information about MCP servers and their tools.
*   **Show Schema:** Display the JSON schema for a tool's parameters.
