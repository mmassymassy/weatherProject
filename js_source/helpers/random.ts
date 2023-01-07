export function getArrayOfRandomNumbers(length: number, max = 1000) {
  return Array.from({ length }, () => Math.floor(Math.random() * max));
}
