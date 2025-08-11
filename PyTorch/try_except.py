from loguru import logger
import traceback

try:
    result = 10 / 0  # This will raise a ZeroDivisionError
except Exception as e:
    logger.error(
        "\n"
        + "".join(
            traceback.format_exception(type(e), e, e.__traceback__)
        ).strip()
    )